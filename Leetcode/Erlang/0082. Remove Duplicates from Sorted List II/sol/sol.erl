%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec delete_duplicates(Head :: #list_node{} | null) -> #list_node{} | null.

matcher(null,    _) -> null;
matcher(Node, Prev) when Node#list_node.next =:= null ->
    case Node#list_node.val =/= Prev of
        true -> Node;
        false -> null
    end;
matcher(Node, Prev) when Node#list_node.next =/= null ->
    case Node#list_node.val =/= Node#list_node.next#list_node.val andalso Node#list_node.val =/= Prev of
        true -> #list_node{val = Node#list_node.val, next = matcher(Node#list_node.next, Node#list_node.val)};
        false -> matcher(Node#list_node.next, Node#list_node.val)
    end.

delete_duplicates(Head) -> matcher(Head, 101).
