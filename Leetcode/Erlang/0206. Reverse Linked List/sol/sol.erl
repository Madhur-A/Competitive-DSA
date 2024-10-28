%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec reverse_list(Head :: #list_node{} | null) -> #list_node{} | null.

reverse_it(H, R) when H =/= null ->
    reverse_it(H#list_node.next, #list_node{val = H#list_node.val, next = R});
reverse_it(null, R) -> R.

reverse_list(Head) -> reverse_it(Head, null).
