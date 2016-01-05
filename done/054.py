# J, Q, K, A -> 11, 12, 13, 14
# H, D, C, S -> 0, 1, 2, 3

# Royal Flush       9
# Straight Flush    8
# Four of a Kind    7
# Full House        6
# Flush             5
# Straight          4
# Three of a Kind   3
# Two Pair          2
# One Pair          1
# Highest Card      0

class card(object):
    def __init__(self, val, suit):
        if val == 'T':
            self.val = 10
        elif val == 'J':
            self.val = 11
        elif val == 'Q':
            self.val = 12
        elif val == 'K':
            self.val = 13
        elif val == 'A':
            self.val = 14
        else:
            self.val = int(val)
        
        if suit == 'H':
            self.suit = 0
        if suit == 'D':
            self.suit = 1
        if suit == 'C':
            self.suit = 2
        if suit == 'S':
            self.suit = 3

def find_rank(hand):
    def consecutive(hand):
        if [hand[x].val for x in xrange(5)] == [14, 5, 4, 3, 2]:
            return True
        for i in range(1, len(hand)):
            if hand[i].val != hand[i - 1].val - 1:
                return False
        return True
    
    def same_suit(hand):
        for i in range(1, len(hand)):
            if hand[i].suit != hand[i - 1].suit:
                return False
        return True
    
    def same_value(hand):
        for i in range(1, len(hand)):
            if hand[i].val != hand[i - 1].val:
                return False
        return True
        
    if consecutive(hand) and same_suit(hand):
        if hand[4].val == 10:
            return 9, NOne
        else:
            return 8, None
    elif same_value(hand[1:]):
        return 7, (hand[1].val, hand[0].val)
    elif same_value(hand[:4]):
        return 7, (hand[0].val, hand[4].val)
    elif (same_value(hand[0:3]) and same_value(hand[3:])):
        return 6, (hand[2].val, hand[3].val)
    elif (same_value(hand[0:2]) and same_value(hand[2:])):
        return 6, (hand[1].val, hand[2].val)
    elif same_suit(hand):
        return 5, None
    elif consecutive(hand):
        return 4, None
    elif same_value(hand[:3]):
        return 3, (hand[0].val, hand[3].val, hand[4].val)
    elif same_value(hand[1:4]):
        return 3, (hand[1].val, hand[0].val, hand[4].val)
    elif same_value(hand[2:]):
        return 3, (hand[2].val, hand[0].val, hand[1].val)
    elif (same_value(hand[:2]) and same_value(hand[2:4])):
        if hand[0].val > hand[2].val:
            return 2, (hand[0].val, hand[2].val, hand[4].val)
        else:
            return 2, (hand[2].val, hand[0].val, hand[4].val)
    elif (same_value(hand[:2]) and same_value(hand[3:])):
        if hand[0].val > hand[3].val:
            return 2, (hand[0].val, hand[3].val, hand[2].val)
        else:
            return 2, (hand[3].val, hand[0].val, hand[2].val)
    elif (same_value(hand[1:3]) and same_value(hand[3:])):
        if hand[1].val > hand[3].val:
            return 2, (hand[1].val, hand[3].val, hand[0].val)
        else:
            return 2, (hand[3].val, hand[1].val, hand[0].val)
    elif same_value(hand[:2]):
        return 1, (hand[0].val, hand[2].val, hand[3].val, hand[4].val)
    elif same_value(hand[1:3]):
        return 1, (hand[1].val, hand[0].val, hand[3].val, hand[4].val)
    elif same_value(hand[2:4]):
        return 1, (hand[2].val, hand[0].val, hand[1].val, hand[4].val)
    elif same_value(hand[3:]):
        return 1, (hand[3].val, hand[0].val, hand[1].val, hand[2].val)
    else:
        return 0, tuple([hand[i].val for i in xrange(5)])


def tie_breaker(hand1, hand2):
    for a, b in zip(hand1, hand2):
        if a > b:
            return 1
        elif a < b:
            return 2
    return 0

data = []
with open('054_input.txt', 'r') as f:
    data = f.readlines()
f.close()

p1_wins = 0
for hands in data:
    cards = hands.split()
    hand1 = sorted([card(c[0], c[1]) for c in cards[:5]], key=lambda card: card.val)[::-1]
    hand2 = sorted([card(c[0], c[1]) for c in cards[5:]], key=lambda card: card.val)[::-1]
    rank1, kicker1 = find_rank(hand1)
    rank2, kicker2 = find_rank(hand2)
    if rank1 > rank2:
        p1_wins += 1
    elif rank1 == rank2:
        if tie_breaker(kicker1, kicker2) == 1:
            p1_wins += 1

print(p1_wins)
