-compile(export_all). % testing phase directive
%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec insert_greatest_common_divisors(Head :: #list_node{} | null) -> #list_node{} | null.

gcd(A, 0) -> A;
gcd(A, B) -> gcd(B, A rem B).

insert(Root) when Root =/= null andalso Root#list_node.next =/= null ->
	#list_node{val = Root#list_node.val, next = #list_node{val = gcd(Root#list_node.val, Root#list_node.next#list_node.val), next = insert(Root#list_node.next)}};
insert(Root) -> Root.

insert_greatest_common_divisors(Head) -> insert(Head).

