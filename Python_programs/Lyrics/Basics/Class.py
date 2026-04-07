class Myclass:
    def __init__(self):
        self._private_var = "I am private"
    
    def _private_method(self):
        return "this is a private method"

    def _show_private(self):
        return self._private_var + " and " + self._private_method()

obj = Myclass()
print(obj._show_private())

#access private using mangling i.e. double underscore
class Myclass_mangling:
    def __init__(self):
        self.__private_var = "I am private"

    def _show_private(self):
        return self.__private_var

obj = Myclass_mangling()
print(obj._Myclass_mangling__private_var)

