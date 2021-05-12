// FIND THE DIAMETER OF A TREE 
// to find the diameter take any node run bfs on the tree starting from that node then find
// the farthest node.
// Now from that node again run bfs to find the furthest node then you will get a long chain
// which you can call the maximum diameter of the graph.

// if you stratch your diameter than the chain which you get in that the subtree's height
// can be determined (the equality can be formed).
// 
//
//   0-0-0-0-0-0-0-0-0
//   1 2 3 4 5 6 7 8 9 any sub-tree at node 2 would be atmost of height of 1
//  any sub-tree at node 5 would be atmost of height of 4.


// for handling the queries in the sub-tree you can store the tree in form of an array
// so that you can easily apply all the properties of segment tree in that array or in
// that sub-tree
// for the above question use the preorder numbering in dfs traversal and while leaving
// the node store the number which was last used.
// After that you can see that the way you numbered you can get any sub-tree by the
// pre-ordering number in that node which points to the positions in the array.

// for finding sum of any path in a tree you can use the euler - tour in which you can
// do the same above thing but at ending of the dfs traversal you should increase the 
// pre-order number. And while storing it in the array for a node which is having a 
// pre-order number and a post-order number you can add +val at pre and -val at post.
