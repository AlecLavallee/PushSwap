# PushSwap
1.Read the args passed in parameters and push them into stack A (if no duplicates or invalid parameters are spotted).
2.Detect if the stack is empty or already sorted.
3.If the stack is 5 elements or less then applies the algorithm for small cases (short_suites.c).
4.If more than 5 elements then execute main algorithm
/* target_index.c */
5.Do a copy of stack A (stack cpy) and run a bubblesort on it to get the targets of each elements.
/* keep_push.c */
6.Find the largest suites of already sorted elements in stack A.
7.Push all the other elements on stack B.
/* main */
8.Main loop for sorting starts
/* find_shortest_action.c */
9.First element on the top of b is next to be sorted.
10.Evaluation and optimization of the best moves to make to sort the element.
11.