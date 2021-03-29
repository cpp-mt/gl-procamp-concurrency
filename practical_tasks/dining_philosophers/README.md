# Dining Philosophers Task

Description:

The table has five plates, five forks and a large bowl of spaghetti in the middle.
As philosophers do, they are either thinking or eating.
Each philosopher needs two forks to eat. He can pick up closest forks to him only: one on his left side and one on his right side. 
Run each philosopher in a separate thread. 
Think of approach that will eliminate deadlock
(don't use std::lock or std::scoped_lock wrapper but implement your own deadlock avoidance algorithm)

 As soon as you are done with a deadlock avoidance algorithm, analyze your approach if "livelock" may occur  (see what can be done to eliminate livelock). 

The list of files which are allowed to be modified:
```
project/dining_philosophers.cpp
```


