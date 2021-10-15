"""
Python program to find all unique elements in a list
Displays all unique elements and count
"""

def unique(arr: list):
    unique_elements = set()
    for element in arr:
        unique_elements.add(element)
    return unique_elements, len(unique_elements)

if __name__ == "__main__":
    unique_elements, count = unique(input("Enter a list seperated by commas\n").split(","))
    print(", ".join(unique_elements))
    print(f"Count: {count}")