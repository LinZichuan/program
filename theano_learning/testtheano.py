import theano
import theano.tensor as T
from theano import Param
from theano.tensor.shared_randomstreams import RandomStreams

x = T.dmatrix('x')
s = 1 / (1 + T.exp(-x))
logistic = theano.function([x], s)
y = logistic([[0, 1], [-1, -2]])
#print y

x, y, w = T.dscalars('x', 'y', 'w')
z = (x + y) * w
f = theano.function([x, Param(y, default=1), Param(w, default=2)], z)
print f(9, w = 1, y = 2)

srng = RandomStreams(seed = 234)
rv_u = srng.uniform((2,2))
rv_n = srng.normal((2,2))
f = theano.function([], rv_u)
z = theano.function([], rv_u + rv_u - 2 * rv_u)
print z
print z()
print rv_u
print rv_n
