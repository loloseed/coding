package binarysearchtree

import(
	"binarytree"
)

type BinarySearchTree struct {
	root *binarytree.BinaryTreeNode
	compareFunc func(v, nodeV interface{}) int
}

func NewBinarySearchTree(values []interface{}, compFunc func(v, nodeV interface{}) int) *BinarySearchTree {
	root := &BinarySearchTree{compareFunc: compFunc}
	for _, v := range values {
		root.Insert(v)
	}
	return root
}

func (this *BinarySearchTree) Insert(v interface{}) bool {
	if nil == this.root {
		this.root = binarytree.NewBinaryTreeNode(v)
		return true
	}
	p := this.root
	for nil != p {
		compResult := this.compareFunc(v, p.GetValue())
		if compResult <= 0 {
			if nil == p.Left {
				p.Left = binarytree.NewBinaryTreeNode(v)
				break
			}
			p = p.Left
		} else {
			if nil == p.Right {
				p.Right = binarytree.NewBinaryTreeNode(v)
				break
			}
			p = p.Right
		}
	}
	return true
}