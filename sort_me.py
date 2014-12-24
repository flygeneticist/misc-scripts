def sort_me(l):
  if type(l) == list and len(l) > 0:
    a = 0
    for b in range(1,len(l)):
      if l[b] < l[a]:
        # placeholder for item @ a
        temp = l[a]
        # swap a and b items
        l[a] = l[b]
        l[b] = temp
        # recursive call with modified list
        sort_me(l)
      else:
        a += 1
    return l
  else:
    return "Argument must of a non-empty list."

print sort_me([2,3,122,35,0,231,9,34,5,0]) #=> [0,1,2,3,4,5]