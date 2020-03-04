package binarysearchtree

import "testing"

func compareFuncInt(v1, v2 interface{}) int {
	if v1.(int) == v2.(int) {
		return 0
	}
	if v1.(int) > v2.(int) {
		return 1
	}
	return -1
}

func TestLowestCommonAncestor(t *testing.T) {
	var nodeValues = []int{1,2,3,4,5,6,7,8,9,10}
	var nodeInterfaceValues = make([]interface{}, len(nodeValues))
	for idx, v := range nodeValues {
		nodeInterfaceValues[idx] = v
	}
	bst := NewBinarySearchTree(nodeInterfaceValues, compareFuncInt)
	node := LowestCommonAncestor(bst, 1, 10)
	if node.GetValue() != 1 {
		t.Errorf("lca should be=%d", 1)
	}
}

func TestLowestCommonAncestor2(t *testing.T) {
	var nodeValues = []int{9,2,3,4,5,6,7,8,1,10}
	var nodeInterfaceValues = make([]interface{}, len(nodeValues))
	for idx, v := range nodeValues {
		nodeInterfaceValues[idx] = v
	}
	bst := NewBinarySearchTree(nodeInterfaceValues, compareFuncInt)
	node := LowestCommonAncestor(bst, 1, 10)
	if node.GetValue() != 9 {
		t.Errorf("lca should be=%d", 9)
	}
}