class Bankaccount:
    def __init__(self, account_number, balence):          # public int var; protected int_var; private int__var
        self.__account_number = account_number
        self.__balence = balence

    def deposit(self, amount):
        if amount > 0:
            self.__balence += amount
        return self.__balence
    
    def withdraw(self, amount):
        if 0 < amount <= self.__balence:
            self.__balence -= amount
        return self.__balence

    def get_balence(self):
        return self.__balence
    
account = Bankaccount("12345", 1000)

#direct access with fail
try:
    account.__balence += 500
except AttributeError:
    print("Direct access to private failed")

#access using methods
print("Your account balence is: ", account.get_balence())

account.deposit(500)
print("Your account balence after deposit is: ", account.get_balence())