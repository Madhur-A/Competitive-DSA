-module(Solution).

%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec is_sub_path(Head :: #list_node{} | null, Root :: #tree_node{} | null) -> boolean().
-spec rx(Head :: #list_node{} | null, Root :: #tree_node{} | null) -> boolean().
-spec dx(Head :: #list_node{} | null, Root :: #tree_node{} | null) -> boolean().

rx(Head, _Root) when Head == null -> true;
rx(Head,  Root) when Root =/= null, Head#list_node.val == Root#tree_node.val ->
	rx(Head#list_node.next, Root#tree_node.left) orelse rx(Head#list_node.next, Root#tree_node.right);
rx(_, _) -> 
	false.

dx(Head, Root) when Root == null -> false;
dx(Head, Root) ->
	case rx(Head, Root) of
		false -> dx(Head, Root#tree_node.left) orelse dx(Head, Root#tree_node.right);
		true -> true
	end.

is_sub_path(Head, Root) -> 
	dx(Head, Root).
