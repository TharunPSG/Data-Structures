import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
df = pd.read_csv("https://raw.githubusercontent.com/selva86/datasets/master/Admission.csv")
df.columns = ["Serial No." ,"GRE_Score", "TOEFL_Score", "University_Rating", "SOP", "LOR", "CGPA", "Research" ,"Chance_of_Admit"]
df.head()
df.info()
df.nunique()
df.describe()
print("Number of missing values present: ",df.isna().sum().sum(), "\n")
df.isna().any()
df.duplicated()
y = "Chance_of_Admit"
for x in df.columns:
  if x != y:
    plt.scatter(df[x], df[y])
    plt.xlabel(x)
    plt.ylabel(y)
    plt.show()
from sklearn.model_selection import train_test_split as tts
x1 = df["CGPA"]
y = df["Chance_of_Admit"]
df = df.drop(columns=["Chance_of_Admit"], axis=1)
X_train, X_test, y_train, y_test = tts(x1, y, test_size=0.5, random_state=42)
print(X_train.shape)
print(X_test.shape)
print(y_train.shape)
print(y_test.shape)
XT = np.array(X_train.values, 'float')
XT = XT / np.max(XT)
Xt = np.array(X_test.values, 'float')
YT = np.array(y_train.values, 'float')
Yt = np.array(y_test.values, 'float')
a0 = 0                  # intercept
a1 = 0                  # slope
lr = 0.0001             # learning rate
iterations = 1000       # number of iterations
error = []              # error array to calculate cost for each iteration
regLambda = 1/4
for itr in range(iterations):
  error_cost = 0
  cost_a0 = 0
  cost_a1 = 0
  for i in range(len(XT)):
    y_pred = a0 + (a1 * (XT[i]))  # predict value for given x
    error_cost = error_cost + (YT[i] - y_pred) ** 2
    for j in range(len(X_train)):
      partial_wrt_a0 = -2 *(YT[j] - (a0 + a1 * XT[j]))                #partial derivative w.r.t a0
      partial_wrt_a1 = (-2) * (XT[j]) * (YT[j] - (a0 + a1 * XT[j]))   #partial derivative w.r.t a1
      cost_a0 = cost_a0 + partial_wrt_a0 + regLambda * (a0**2 + a1**2)    #calculate cost for each number and add
      cost_a1 = cost_a1 + partial_wrt_a1 + regLambda * (a0**2 + a1**2)    #calculate cost for each number and add
    a0 = a0 - lr * cost_a0    # update a0
    a1 = a1 - lr * cost_a1    # update a1
    print(itr, a0, a1)          # check iteration and updated a0 and a1
  error.append(error_cost)      # append the data in array
