#pragma once
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

class Account {
public:
  Account(std::string user, std::string pass)
      : username(user), password(pass) {};

  std::string &getUsername() { return username; }
  std::string &getPassword() { return password; }
  double &getBalance() { return balance; }

  void deposit(Account &user);
  void withdraw(Account &user);
  bool logout();

private:
  double balance{0};
  std::string username;
  std::string password;
};

class BankSystem {
public:
  void run();

private:
  std::vector<std::unique_ptr<Account>> accounts{};
  std::optional<std::reference_wrapper<Account>> login();
  int menu();
  void signup();
  void dashboard(Account &user);
};
