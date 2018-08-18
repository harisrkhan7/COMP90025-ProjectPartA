import random
for num_vertices in [ 750, 1000, 1250, 1500, 2000, 3000, 5000 ]:
    matrix = [ [ random.randint(1, 10) for a in range(num_vertices) ] for b in range(num_vertices) ]
    with open("randograph-{}.txt".format(num_vertices), "w") as f:
        f.write("{}\n".format(num_vertices))
        for i in range(num_vertices):
            for j in [ random.randint(0, num_vertices - 1) for _ in range(10) ]:
                f.write("{} {} {}\n".format(i+1, j+1, matrix[i][j]))
