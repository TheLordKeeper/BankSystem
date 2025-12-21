#ifndef classes
#define classes

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

private:
  int balance{0};
  std::string username;
  std::string password;
};

class BankSystem {
public:
  void run();

private:
  std::vector<std::unique_ptr<Account>> accounts{};
  std::optional<Account> login();
  int menu();
  void signup();
  void dashboard(Account user);
};

#endif
