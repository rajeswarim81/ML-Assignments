
import pandas as pd 
import numpy as np
from sklearn.neighbors import KNeighborsClassifier

df=pd.read_csv("train.csv", header=None)
x=df[df.columns[0:4]]
y=df[df.columns[4:5]]
df_=pd.read_csv("test.csv", header=None)
z=df_[df_.columns[0:4]].values

print y.size

nb=KNeighborsClassifier(n_neighbors=5)
k=nb.fit(x,y.values.ravel()).predict(z)
print k
#print(pr)
