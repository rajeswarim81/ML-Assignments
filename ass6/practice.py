import numpy as np 
import pandas as pd
from sklearn.datasets import load_digits
from sklearn.linear_model import Perceptron

df=pd.read_csv('data6.csv',header=None)
df=np.asarray(df)
x=df[:,:-1]
y=df[:,-1]

df1=pd.read_csv('test6.csv', header=None)
test=np.asarray(df1)

clf=Perceptron(alpha=0.1, max_iter=10)
clf.fit(x,y)
print(test)
result=clf.predict(test)
print(result)
