%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec is_same_tree(P :: #tree_node{} | null, Q :: #tree_node{} | null) -> boolean().

is_same_tree(null, null) -> true;
is_same_tree(P, Q) when P =/= null andalso Q =/= null ->
    (P#tree_node.val =:= Q#tree_node.val) andalso is_same_tree(P#tree_node.left, Q#tree_node.left) andalso is_same_tree(P#tree_node.right, Q#tree_node.right);
is_same_tree(   _,    _) -> false.
