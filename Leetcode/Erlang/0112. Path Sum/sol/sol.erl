%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec has_path_sum(Root :: #tree_node{} | null, TargetSum :: integer()) -> boolean().

rx(null, _, _) -> false;
rx(Node, T, C) when Node =/= null andalso Node#tree_node.left =:= null andalso Node#tree_node.right =:= null ->
    T =:= C + Node#tree_node.val;
rx(Node, T, C) when Node =/= null ->
    rx(Node#tree_node.left, T, C + Node#tree_node.val) orelse rx(Node#tree_node.right, T, C + Node#tree_node.val).

has_path_sum(Root, TargetSum) -> rx(Root, TargetSum, 0).
