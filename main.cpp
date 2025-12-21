#include "classes.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <optional>

std::optional<Account> BankSystem::login() {
  std::string username{};
  std::string password{};

  std::system("clear");
  std::cout << "Please enter your username: ";
  std::cin >> username;

  std::cout << "Please enter your password: ";
  std::cin >> password;
  ;
  for (const auto &acc : accounts) {
    if (username == acc->getUsername() && password == acc->getPassword()) {
      return *acc;
    }
  };
  return std::nullopt;
}

void BankSystem::signup() {
  std::string username{};
  std::string password{};

  std::system("clear");
  std::cout << "Please enter your username: ";
  std::cin >> username;

  for (const auto &acc : accounts) {
    if (username == acc->getUsername()) {
      std::cout << "This username is already taken!\n\n";
      return;
    }
  }

  std::cout << "Please enter your password: ";
  std::cin >> password;

  accounts.push_back(std::make_unique<Account>(username, password));
  std::cout << "Account Created!";

  return;
}

int BankSystem::menu() {
  int choice{};
  std::cout << "Welcome to the bank! Please choose an option:\n1: Login\n2: "
               "Sign up\n0: Exit\n";
  std::cin >> choice;
  return choice;
}

void ::BankSystem::dashboard(Account user) {
  std::system("clear");
  return;
}

void BankSystem::run() {
  bool running{true};

  while (running) {

    switch (menu()) {
    case 1:
      if (auto result = login()) {
        dashboard(*result);
      } else {
        std::system("clear");
        std::cout << "Login Failed!\n\n";
      }
      break;
    case 2:
      signup();
      break;
    default:
      return;
    }
  }
}

int main() {
  BankSystem bank;
  bank.run();
  return 0;
}
