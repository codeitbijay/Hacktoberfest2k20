def message(name, greeting):
    '''(str,str)->None
        input must be a string
        prints a message to the screen when called '''
    indent = "__"
    starts = (len(name)+len(greeting)+len(indent)*2+2)
    print()
    print(starts*"*")
    print("*"+(starts-2)*" "+"*")
    print("*", indent, name, greeting, indent, "*")
    print("*" + (starts - 2) * " " + "*")
    print(starts * "*")
    print()


class employee:
    users = {"admin": [],
             "maintenance": [],
             "worker": []
             }

    def __init__(self, name, email, tag, work):
        '''
     gets the information provided by the employee
    '''
        self._name = name
        self._email = email
        self._tag = tag
        self._work = work

    def add(self):
        '''
     adds a user to the system of choice
    '''
        if self._work == "a":
            self.users["admin"].append((self._name, self._tag, self._email))
        elif self._work == "m":
            self.users["maintenance"].append((self._name, self._tag, self._email))
        elif self._work == "w":
            self.users["worker"].append((self._name, self._tag, self._email))

    @classmethod
    def remove(cls, name):
        '''
        (None) -> None
        removes a user from the systems list
        '''

        for value in cls.users.values():
            for user in value:
                if name in user:
                    value.remove(user)
                    print("you are now logged out")

    @classmethod
    def pr_user(cls):
        '''
        (None) -> None
        displays the users using each system
        '''
        if len(cls.users) >= 1:
            for keys in cls.users:
                print(("systems users {}:{}").format(keys, cls.users[keys]))


message("Hello!!! welcome", "")
i = 0
shutdown = True
while shutdown:
    question = input("what do you want to do toaday?\n (1) for login, (2) for logout, (3) to see current users and (4) to shutdown\n")
    if question.isalpha():
        print("Option not available please try again")
    else:
        question = int(question)
        if question == 1:
            name = input("Please what is your full name? : ")
            email = input("what is your email? : ")
            tag = input("what is your tag? : ")
            position = input("what system would you like to use?\n (a) for admin, (m) for maintainance, (w) for worker: ")
            if position.strip().lower() == "a" or "b" or "c":
                person = employee(name, email, tag, position)
                person.add()
            else:
                print("there is no such position")
        elif question == 2:
            name = input("please provide your full name")
            employee.remove(name)
        elif question == 3:
            employee.pr_user()
        elif question == 4:
            message("Goodbye", "")
            shutdown = False
        else:
            print("Invalid number, please try again")
