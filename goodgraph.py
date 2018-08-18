import random
num_vertices = 1000
matrix = [ [ random.randint(1, 10) for a in range(num_vertices) ] for b in range(num_vertices) ]
with open("randograph.txt", "w") as f:
    f.write("{}\n".format(num_vertices))
    for i in range(num_vertices):
        for j in range(num_vertices):
            if random.randint(0, 120) == 3:
                f.write("{} {} {}\n".format(i+1, j+1, matrix[i][j]))

