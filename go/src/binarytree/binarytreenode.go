package binarytree

type BinaryTreeNode struct {
	value interface{}
	Left *BinaryTreeNode
	Right *BinaryTreeNode
}

func (this *BinaryTreeNode) GetValue() interface{} {
	return this.value;
}

func NewBinaryTreeNode (v interface{}) *BinaryTreeNode {
	return &BinaryTreeNode{value: v}
}