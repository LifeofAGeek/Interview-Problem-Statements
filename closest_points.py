def closest_points(points,k,p):
  d={i:((p[0]-i[0])**2 + (p[1]-i[1])**2)**(1/2) for i in points}
  l=sorted(d, key=d.get)
  return l[:k]
