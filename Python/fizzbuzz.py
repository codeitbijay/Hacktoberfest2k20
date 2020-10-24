def run_fizzbuzz(ceiling=25):
    """
    Prints out a game of fizzbuzz up to the value of `ceiling`.
    :param ceiling: maximum value to count up to.
    :return: None
    """
    for i in range(1, ceiling + 1):
        message = ''.join(('fizz' if not i % 3 else '', 'buzz' if not i % 5 else ''))
        print(message if message else str(i))
    return

if __name__ == '__main__':
    run_fizzbuzz()

