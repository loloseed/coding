对于二叉搜索树root，最近子结点node1和node2的公共祖先。

最初想法
1. 从root到node1的路径，记录到path1。
2. 从root到node2的路径，记录到path2。
3. 求path1和path2从后到前第一个相同的值。
4. 这个算法时间是O(h)？(第3步复杂度不应该是hO(h)吗？)，空间O(h)

进一步想，有必要用空间O(h)来保存root到结点的路径吗？
1. 从root开始搜索，如果node1和node2比root都要小，说明它们都在root的左边，那么root的左儿子一定是它们两更近的共同祖先。
2. 如果node1比root小，node2比root大，那么root的左儿子一定不是node2的祖先，root的右儿子一定不是node1的祖先，root就是它两最近的共同祖先。
3. 如果root等于node1或者node2，那么root就是最近共同祖先。