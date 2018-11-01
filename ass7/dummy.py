import pandas as pd 
import numpy as np

import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from scipy.spatial.distance import cdist

df=pd.read_csv('data7.csv', header=None)
#Y=df[df.columns[0:1]]
X=df
print(X.shape)
#plt.figure(num="1. Original Dataset")
#plt.scatter(X,Y, label='True Position')

#error = []
k=2
kmeans = KMeans(n_clusters=k, max_iter=10).fit(X)
print(kmeans.labels_)