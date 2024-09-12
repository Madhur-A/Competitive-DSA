%% -module(sol).
-compile(export_all). %% testing phase directive

%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec inorder_traversal(Root :: #tree_node{} | null) -> [integer()].


inorder_traversal(null) -> [];
inorder_traversal(Root) ->
	inorder_traversal(Root#tree_node.left) ++ [Root#tree_node.val] ++ inorder_traversal(Root#tree_node.right).

