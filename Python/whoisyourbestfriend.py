# This code might not work as expect, please pip install the package and read the documentation for more information
# https://fbchat.readthedocs.io/en/stable/index.html
from fbchat import Client
from fbchat.models import Message


username = "<ur email>"
password = "<ur password>"
client = Client(username, password)
# 20 users info
users = client.fetchThreadList()

detailed_users = [ list(client.fetchThreadInfo(user.uid).values())[0] for user in users ]

sorted_detailed_users = sorted(detailed_users, key=lambda u: u.message_count, reverse=True)

best_friend = sorted_detailed_users[0]
second = sorted_detailed_users[1]
third = sorted_detailed_users[2]
forth = sorted_detailed_users[3]
fifth = sorted_detailed_users[4]
sixth = sorted_detailed_users[5]
seventh = sorted_detailed_users[6]
eighth = sorted_detailed_users[7]
nineth = sorted_detailed_users[8]
tenth = sorted_detailed_users[9]
eleventh = sorted_detailed_users[10]



print("\n Your top eleven people/groups message numbers:\n"\
    "", "No.1:", best_friend.name, "with", best_friend.message_count, "messages\n", \
    "No.2:", second.name, "with", second.message_count, "messages\n", \
        "No.3:", third.name, "with", third.message_count, "messages\n", \
            "No.4:", forth.name, "with", forth.message_count, "messages\n", \
                "No.5:", fifth.name, "with", fifth.message_count, "messages\n", \
                    "No.6:", sixth.name, "with", sixth.message_count, "messages\n", \
                        "No.7:", seventh.name, "with", seventh.message_count, "messages\n", \
                            "No.8:", eighth.name, "with", eighth.message_count, "messages\n", \
                                "No.9:", nineth.name, "with", nineth.message_count, "messages\n",\
                                    "No.10:", tenth.name, "with", tenth.message_count, "messages\n",\
                                        "No.11:", eleventh.name, "with", eleventh.message_count, "messages\n")
            # "Third: ", third.name, "with a message count of", third.messsage_count,\
            #     "Forth: ", forth.name, "with a message count of", forth.message_count)

client.logout()