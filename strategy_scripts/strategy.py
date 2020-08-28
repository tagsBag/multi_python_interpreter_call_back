import math

if(Context.x <= 1):
	Context.y = math.cos(2 * Context.x)
else:
	Context.y = Context.x ** 1.5


if(Context.x == 1):
	Context.whoami()


