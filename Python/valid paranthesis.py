class Solution(object):
    def isValid(self, s):

        myStack = []
        count = 0  # keep track of number of elements

        # used to find closing brackets
        match = {
            "(": ")",
            "[": "]",
            "{": "}"
        }

        for par in s:
            # handle opening brackets
            if par == "(" or par == "{" or par == "[":
                myStack.append(par)
                count += 1

            # handle closing brackets
            else:
                # check if we can find the corresponding opening bracket
                if count < 1 or match[myStack.pop()] != par:
                    return False
                # the pop() above removed a alement from the stack
                count -= 1

        # return true if stack is empty(all matched successfully)
        return count == 0
