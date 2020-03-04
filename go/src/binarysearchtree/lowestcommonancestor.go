// 计算二叉树中2个结点的最近公共祖�?
// 最初想�?
// 算法时间复杂度O(h)，其中h是树高，空间复杂度O(1)

package binarysearchtree

import(
	"binarytree"
)

func LowestCommonAncestor(tree *BinarySearchTree, value1 interface{}, value2 interface{}) *binarytree.BinaryTreeNode {
	return lca(tree.root, value1, value2, tree.compareFunc)

}

func lca(root *binarytree.BinaryTreeNode,
	value1 interface{},
	value2 interface{},
	compareFunc func(v, nodeV interface{}) int) *binarytree.BinaryTreeNode {
	curNode := root
	compResultValue1 := compareFunc(value1, curNode.GetValue())
	compResultValue2 := compareFunc(value2, curNode.GetValue())
	if 0 == compResultValue1 || 0 == compResultValue2 {
		return curNode
	}
	if compResultValue1 != compResultValue2 {
		// value1和value2在curNode两边，当前节点是最近公共祖先
		return curNode
	}
	if compResultValue1 < 0 {
		// value1和value2在左
		return lca(curNode.Left, value1, value2, compareFunc)
	}
	// value1和value2在右
	return lca(curNode.Right, value1, value2, compareFunc)
}