#include "classes.hpp"
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>

std::optional<std::reference_wrapper<Account>> BankSystem::login() {
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
      return std::ref(*acc);
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

  std::system("clear");
  std::cout << "Account Created!\n\n";

  return;
}

int BankSystem::menu() {
  int choice{};
  std::cout << "Welcome to the bank! Please choose an option:\n1: Login\n2: "
               "Sign up\n0: Exit\n";
  std::cin >> choice;
  return choice;
}

bool Account::logout() {
  std::system("clear");

  int choice{0};
  std::cout << "Are you sure you want to logout?\n1:Yes\n0:No\n";
  std::cin >> choice;

  if (choice == 1) {
    return true;
  } else {
    return false;
  }
}

void Account::deposit(Account &user) {
  std::system("clear");
  double amount{0.0};
  std::cout << "Balance: $" << user.getBalance()
            << "\n\nPlease enter the amount you wish to deposit: $";
  std::cin >> amount;

  std::system("clear");

  if (amount < 0) {
    std::cout << "Error! Invalid value!\n\n";
    return;
  }

  user.getBalance() += amount;
  std::cout << "Operation sucessful!\n\n";
}

void Account::withdraw(Account &user) {
  std::system("clear");
  double amount{0.0};
  std::cout << "Balance: $" << user.getBalance()
            << "\n\nPlease enter the amount you wish to withdraw: $";
  std::cin >> amount;

  std::system("clear");

  if (amount < 0) {
    std::cout << "Error! Invalid value!\n\n";
    return;
  }

  if (user.getBalance() >= amount) {
    user.getBalance() -= amount;
    std::cout << "Operation sucessful!\n\n";
  } else {
    std::cout << "You do not have the required balance!\n\n";
  }

  return;
}

void ::BankSystem::dashboard(Account &user) {
  std::system("clear");

  bool running{true};
  while (running) {
    int choice{0};
    std::cout
        << "Balance: $" << user.getBalance() << "\n\nWelcome, "
        << user.getUsername()
        << "! Please choose an option:\n1: Deposit\n2: Withdraw\n0: Logout\n";

    std::cin >> choice;

    switch (choice) {
    case 1:
      user.deposit(user);
      break;
    case 2:
      user.withdraw(user);
      break;
    default:
      if (user.logout()) {
        std::system("clear");
        return;
      }
      break;
    }
  }
}

void BankSystem::run() {
  std::system("clear");
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
