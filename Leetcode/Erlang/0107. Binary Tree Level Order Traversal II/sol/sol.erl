%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec level_order_bottom(Root :: #tree_node{} | null) -> [[integer()]].

get_nodes(null,  null) -> [];
get_nodes(null, Right) -> [Right];
get_nodes(Left,  null) -> [Left];
get_nodes(Left, Right) -> [Left, Right].

get_all_children(   []) -> [];
get_all_children(Roots) -> [get_nodes(Root#tree_node.left, Root#tree_node.right) || Root <- Roots, Root =/= null].

get_value(Root) -> Root#tree_node.val.

lrx(   [], Res) -> Res;
lrx(Roots, Res) ->
    lrx(lists:flatten(get_all_children(Roots)), [[get_value(Root) || Root <- Roots, Root =/= null]] ++ Res).

level_order_bottom(null) -> [];
level_order_bottom(Root) -> lrx([Root], []).

clear() ->
    io:format("\ec").
