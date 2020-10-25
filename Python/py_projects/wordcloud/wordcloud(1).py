#!/usr/bin/env python
# coding: utf-8

# In[2]:


get_ipython().system('pip install wordcloud')


# In[4]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# In[15]:


frnd_df = pd.read_csv('friends.csv')


# In[16]:


frnd_df


# In[7]:


from wordcloud import WordCloud , ImageColorGenerator


# In[17]:


comment_words = '' 
  
# iterate through the csv file 
for val in frnd_df.NAME: 
      
    # typecaste each val to string 
    val = str(val) 
  
    # split the value 
    tokens = val.split() 
      
    # Converts each token into lowercase 
    for i in range(len(tokens)): 
        tokens[i] = tokens[i].lower() 
      
    comment_words += " ".join(tokens)+" "
wordcloud = WordCloud(width = 400, height = 400, background_color ='white', 
                min_font_size = 10).generate(comment_words)                  
plt.figure(figsize = (8, 8), facecolor = None) 
plt.imshow(wordcloud) 
plt.axis('off') 
plt.show()


# In[ ]:




