# Python Sieve of Eratosthenes - https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
# The idea of the sieve of Eratosthene is to start with the list of all integer starting at 2 up to the limit we want to compute.
# A prime number is not the multiple of any number except 0, 1 and itself.
# So a way to find all primes up to the limit is to remove all multiples of the primes we currently know of starting at 2.
class Solution:
    def countPrimes(self, n: int) -> int:
        candidates = list(range(2,n))
        for idx, num in enumerate(candidates):
            if num is not None:
                for multiple in range(idx+num, len(candidates), num):
                    candidates[multiple] = None
        return sum(1 for i in candidates if i is not None)
        
# This algorithm is good if you want preprocessed data of prime numbers. #SharingKnowledge #Hacktoberfest2020
