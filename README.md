# Consistent-Hashing
In Distributed Hashing, the objects (and their keys) are distributed among several servers.

## Problems With Normal Hashing 

After removing one of the server, have to reassign each & every key to the different servers.Similarly if we add a new server have to reassign each & every server. 

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/8b89e193-2fbd-4212-b230-7addb957b470)

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/95e50cbb-88fa-456c-8354-72d58a59af1e)

## Solution With Consistent Hashing 

Consistent Hashing is a distributed hashing scheme that operates independently of the number of servers or objects in a distributed hash table by assigning them a position on an abstract circle, or hash ring. This allows servers and objects to scale without affecting the overall system.

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/2864879e-977d-4f23-8915-22ed55a902cc)

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/65d5605a-35d4-4a4d-9104-ae430a9bcccf)


To ensure object keys are evenly distributed among servers, we need to apply a simple trick: To assign not one, but many labels (angles) to each server. So instead of having labels A, B and C, we could have, say, A0 .. A9, B0 .. B9 and C0 .. C9, all interspersed along the circle.

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/e40ef039-556a-49d7-8f80-be879a6447d4)

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/946482ca-3a46-4258-8095-7b55b8652336)

![image](https://github.com/omprakashpatel27/Consistent-Hashing/assets/59342793/e0f61185-1bc0-4f91-a3f1-cb86df09b290)


So, what’s the benefit of all this circle approach? Imagine server C is removed. To account for this, we must remove labels C0 .. C9 from the circle. This results in the object keys formerly adjacent to the deleted labels now being randomly labeled Ax and Bx, reassigning them to servers A and B.

But what happens with the other object keys, the ones that originally belonged in A and B? Nothing! That’s the beauty of it: The absence of Cx labels does not affect those keys in any way. So, removing a server results in its object keys being randomly reassigned to the rest of the servers, leaving all other keys untouched.

## Reference
https://www.toptal.com/big-data/consistent-hashing
