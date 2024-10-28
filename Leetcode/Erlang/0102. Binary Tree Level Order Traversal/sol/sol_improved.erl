 %% -module(sol_improved).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

%% Definition for a binary tree node.
-record(tree_node, {val = 0 :: integer(),
                    left = null  :: 'null' | #tree_node{},
                    right = null :: 'null' | #tree_node{}}).

-spec level_order(Root :: #tree_node{} | null) -> [[integer()]].

get_nodes(null,  null) -> [];
get_nodes(null, Right) -> [Right];
get_nodes(Left,  null) -> [Left];
get_nodes(Left, Right) -> [Left, Right].

lrx(   [], Res) -> Res;
lrx(Roots, Res) ->
    lrx(lists:flatten([get_nodes(Root#tree_node.left, Root#tree_node.right) || Root <- Roots, Root =/= null]),
        Res ++ [[Root#tree_node.val || Root <- Roots, Root =/= null]]).

level_order(null) -> [];
level_order(Root) -> lrx([Root], []).

clear() ->
    io:format("\ec").
