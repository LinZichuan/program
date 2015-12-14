import numpy
import theano
import theano.tensor as T
rng = numpy.random

N = 400
feats = 784
D = (rng.randn(N, feats), rng.randint(size=N, low=0, high=2))
print D[0]

x = T.matrix("x")
y = T.vector("y")
w = theano.shared(rng.randn(feats), name="w")
b = theano.shared(0., name="b")
print("Initial model:")
print(w.get_value())
print(b.get_value())

p = 1 / (1 + T.exp(-T.dot(x, w) - b))   # Probability that target = 1
prediction = p > 0.5                    # The prediction thresholded
xent = -y * T.log(p) - (1-y) * T.log(1-p) # Cross-entropy loss function
cost = xent.mean() + 0.01 * (w ** 2).sum()# The cost to minimize
gw, gb = T.grad(cost, [w, b])             # Compute the gradient of the cost
                                          # (we shall return to this in a
                                          # following section of this tutorial)

