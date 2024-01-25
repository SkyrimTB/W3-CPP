#include <iostream>
#include <memory>
#include <string>

// TreeNode represents each node in the decision tree
class TreeNode {
public:
  std::string data;
  std::unique_ptr<TreeNode> yesChild;
  std::unique_ptr<TreeNode> noChild;

  TreeNode(const std::string &data) : data(data) {}
};

// AnimalGame manages the game logic
class AnimalGame {
private:
  std::unique_ptr<TreeNode> root;

public:
  AnimalGame() {
    // Initialize the game with one question and two animals
    root = std::make_unique<TreeNode>("Does it fly?");
    root->yesChild = std::make_unique<TreeNode>("Eagle");
    root->noChild = std::make_unique<TreeNode>("Lion");
  }

  // Function to start the game
  void playGame() {
    std::cout << "Think of an animal, and I will try to guess it." << std::endl;
    guessAnimal(root.get(), nullptr, false);
  }

  // Recursive function to traverse the tree and make guesses
  void guessAnimal(TreeNode *currentNode, TreeNode *parentNode,
                   bool isYesChild) {
    if (!currentNode->yesChild && !currentNode->noChild) {
      // We are at a leaf node, so make a guess
      std::cout << "Is it a " << currentNode->data << "? (yes/no)" << std::endl;
      std::string answer;
      std::getline(std::cin, answer);
      if (answer == "yes") {
        std::cout << "Hooray! I guessed it!" << std::endl;
      } else {
        learnNewAnimal(currentNode, parentNode, isYesChild);
      }
    } else {
      // Ask a question and recurse based on the answer
      std::cout << currentNode->data << " (yes/no)" << std::endl;
      std::string answer;
      std::getline(std::cin, answer);
      if (answer == "yes") {
        guessAnimal(currentNode->yesChild.get(), currentNode, true);
      } else {
        guessAnimal(currentNode->noChild.get(), currentNode, false);
      }
    }
  }

  // Function to learn a new animal if the guess was wrong
  void learnNewAnimal(TreeNode *currentNode, TreeNode *parentNode,
                      bool isYesChild) {
    std::cout << "I give up. What animal were you thinking of?" << std::endl;
    std::string newAnimal;
    std::getline(std::cin, newAnimal);

    std::cout << "Please give me a question to distinguish a " << newAnimal
              << " from a " << currentNode->data << "." << std::endl;
    std::string newQuestion;
    std::getline(std::cin, newQuestion);

    std::cout << "What is the answer for a " << newAnimal << "? (yes/no)"
              << std::endl;
    std::string answer;
    std::getline(std::cin, answer);

    // Update the tree with the new animal and question
    auto newAnimalNode = std::make_unique<TreeNode>(newAnimal);
    auto oldAnimalNode = std::make_unique<TreeNode>(currentNode->data);

    currentNode->data = newQuestion;
    if (answer == "yes") {
      currentNode->yesChild = std::move(newAnimalNode);
      currentNode->noChild = std::move(oldAnimalNode);
    } else {
      currentNode->yesChild = std::move(oldAnimalNode);
      currentNode->noChild = std::move(newAnimalNode);
    }
  }

  // Function to reset the game to its initial state
  void forgetGame() {
    root.reset();
    root = std::make_unique<TreeNode>("Does it fly?");
    root->yesChild = std::make_unique<TreeNode>("Eagle");
    root->noChild = std::make_unique<TreeNode>("Lion");
    std::cout << "Game has been reset to its initial state." << std::endl;
  }
};

// Main function
int main() {
  AnimalGame game;
  std::string command;

  do {
    std::cout << "Enter 'play' to start the game, 'forget' to reset the game, "
                 "or 'exit' to exit: ";
    std::getline(std::cin, command);

    if (command == "play") {
      game.playGame();
    } else if (command == "forget") {
      game.forgetGame();
    }
  } while (command != "exit");

  return 0;
}
