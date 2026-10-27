# CS 300 Project One — Data Structure Run-Time and Memory Analysis

This portfolio artifact contains the run-time analysis, advantages and disadvantages, and final recommendation from my CS 300 Project One. The project compared vectors, hash tables, and binary search trees for a computer science course advising program.

## Vector — Runtime Analysis

| Code | Line Cost | # Times Executes | Total Cost |
| --- | --- | --- | --- |
| Open file and check | 1 | 1 | 1 |
| Read course line | 1 | n | n |
| Split line and check format | 1 | n | n |
| Create and fill course object | 1 | n | n |
| Store prerequisites | 1 | Up to 2n | 2n |
| Add course to vector | 1 | n | n |
| Loop through courses | 1 | n | n |
| Loop through prerequisites | 1 | Up to 2n | 2n |
| Compare prerequisites with course list | 1 | Up to 2n² | 2n² |
| Close file | 1 | 1 | 1 |

**Total Cost (upper bound):** 2n² + 9n + 2  
**Runtime:** O(n²)

## Hash Table — Runtime Analysis

| Code | Line Cost | # Times Executes | Total Cost |
| --- | --- | --- | --- |
| Open file and check | 1 | 1 | 1 |
| Read course line | 1 | n | n |
| Split line and check format | 1 | n | n |
| Create and fill course object | 1 | n | n |
| Store prerequisites | 1 | Up to 2n | 2n |
| Add course numbers to temporary vector | 1 | n | n |
| Add courses to temporary vector | 1 | n | n |
| Loop through courses | 1 | n | n |
| Loop through prerequisites | 1 | Up to 2n | 2n |
| Check prerequisites against course numbers | 1 | Up to 2n² | 2n² |
| Loop through courses for insertion | 1 | n | n |
| Insert into hash table | O(n) worst case | n | O(n²) |
| Close file | 1 | 1 | 1 |

**Total Cost (upper bound):** 3n² + 11n + 2  
**Runtime:** O(n²)

## Binary Search Tree — Runtime Analysis

| Code | Line Cost | # Times Executes | Total Cost |
| --- | --- | --- | --- |
| Open file and check | 1 | 1 | 1 |
| Read course line | 1 | n | n |
| Split line and check format | 1 | n | n |
| Create and fill course object | 1 | n | n |
| Store prerequisites | 1 | Up to 2n | 2n |
| Add course to temporary vector | 1 | n | n |
| Loop through courses | 1 | n | n |
| Loop through prerequisites | 1 | Up to 2n | 2n |
| Check prerequisites against course list | 1 | Up to 2n² | 2n² |
| Loop through courses for insertion | 1 | n | n |
| Insert into BST | O(n) worst case | n | O(n²) |
| Close file | 1 | 1 | 1 |

**Total Cost (upper bound):** 3n² + 10n + 2  
**Runtime:** O(n²)

## Advantages and Disadvantages

### Vector

A vector is simple to use and makes it easy to store course information. However, searching for a specific course can take longer because the program may need to check each course individually. The courses also need to be sorted before printing them in order. Vectors generally use memory efficiently.

### Hash Table

A hash table allows courses to be searched quickly using their course numbers. This makes searching more efficient in most cases. However, collisions can slow down searches, and the courses must be sorted separately to display them in order. Hash tables also require additional memory for their buckets.

### Binary Search Tree

A binary search tree organizes courses by course number, allowing them to be printed in alphanumeric order without additional sorting. Searching can also be efficient when the tree is balanced. However, an unbalanced tree can slow down searching and insertion, and each node requires additional memory for its connections.

## Final Recommendation

After comparing the three data structures, I would recommend using a Binary Search Tree for the course advising program. One of the main advantages is that it allows courses to be printed in alphanumeric order without needing a separate sorting process. It also allows for efficient searching when the tree is balanced.

Although all three structures had a worst-case loading time of O(n²) in my analysis, the Binary Search Tree would be a good choice because it supports both of the main tasks required by the advising program. Its main disadvantage is that performance can decrease if the tree becomes unbalanced.

---

*Portfolio extract from my original CS 300 Project One submission. The analysis and conclusions have been preserved from the submitted document.*
