
import pandas as pd 
import numpy as np
from sklearn.naive_bayes import BernoulliNB

df=pd.read_csv("data3.csv", header=None)
x=df[df.columns[0:8]]
y=df[df.columns[8:9]]
df_=pd.read_csv("test3.csv", header=None)
z=df_[df_.columns[0:8]].values

print y.size

nb=BernoulliNB(alpha=1.0)
k=nb.fit(x,y.values.ravel()).predict(z)
print k
#print(pr)
