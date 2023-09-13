class Solution(object):
    def traverse(self,root,res):
        if root==None:
            return res
        if root.left==None and root.right==None:
            res.append(root.val)
            return res
        self.traverse(root.left,res)
        res.append(root.val)
        self.traverse(root.right,res)
        return res

    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        list1=[]
        list2=[]
        list1=self.traverse(root1,list1)
        list2=self.traverse(root2,list2)
        i=0
        j=0
        while(i<len(list1) and j<len(list2)):
            if list1[i]<list2[j]:
                i+=1
            elif list1[i]==list2[j]:
                list1.insert(i,list2[j])
                i+=2
                j+=1
            elif list1[i]>list2[j]:
                list1.insert(i,list2[j])
                i+=1
                j+=1
        while j<len(list2):
            list1.append(list2[j])
            j+=1
        return list1
