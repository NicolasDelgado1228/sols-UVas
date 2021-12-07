class state:
	def __init__(self):
		self.length = int()
		self.link = int()
		self.d = -1
		self.next = dict()

MAXLEN = int()
st = list()
sz = int()
last = int()

def sa_init():
	global MAXLEN, st, sz, last
	sz = last = 0
	st[0].length = 0
	st[0].link = -1
	sz += 1

def sa_extend(c):
	global MAXLEN, st, sz, last
	cur = sz; sz += 1
	st[cur].length = st[last].length + 1
	p = last
	while p != -1 and c not in st[p].next:
		st[p].next[c] = cur
		p = st[p].link

	if p == -1:
		st[cur].link = 0
	else:
		q = st[p].next[c]
		if st[p].length + 1 == st[q].length:
			st[cur].link = q
		else:
			clone = sz; sz += 1
			st[clone].length = st[p].length + 1
			st[clone].next = st[q].next
			st[clone].link = st[q].link
			while p != -1 and c in st[p].next and st[p].next[c]==q:
				st[p].next[c] = clone
				p = st[p].link
			st[q].link = st[cur].link = clone;
	last = cur

def buildAutomaton(s):
	global MAXLEN, st, sz, last
	n = len(s)
	st = [state() for _ in range(n*2)]
	sa_init()
	for c in s: sa_extend(c)




def show():
	global MAXLEN, st, sz, last
	for s in st: print(s.next)

def main():
	global MAXLEN, st, sz, last
	word = "Foundations.TheRoleOfAlgorithmsInComputing.GettingStarted.Theorem.SortingAlgorithms.TheHeapsort.Quicksort."
	for c in word: sa_extend(c)
	show()

main()