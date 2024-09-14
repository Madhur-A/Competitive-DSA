%% -module(sol).
-compile(export_all). % testing phase directive


%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

%% -spec path_sum(Root :: #tree_node{} | null, TargetSum :: integer()) -> [[integer()]].

is_leaf(null) -> false;
is_leaf(#tree_node{left = Left, right = Right}) -> Left =:= null andalso Right =:= null.

sum([]) -> 0;
sum([First|Rest]) -> First + sum(Rest).

valid_paths(Path, Target) ->
	sum(Path) =:= Target.

all_paths(null, _) -> [];
all_paths(Node, CurrPath) -> 
	case is_leaf(Node) of
		true -> [CurrPath ++ [Node#tree_node.val]];
		_    -> all_paths(Node#tree_node.left, CurrPath ++ [Node#tree_node.val]) ++ all_paths(Node#tree_node.right, CurrPath ++ [Node#tree_node.val])
	end.

path_sum(Root, TargetSum) ->
	Paths = all_paths(Root, []),
	lists:filter(fun(Path) -> sum(Path) =:= TargetSum end, Paths).

clear() ->
	io:format("\ec").
