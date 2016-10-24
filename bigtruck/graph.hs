import Control.Monad
import Data.List

data Node = Node {index :: Int, boxes :: Int} deriving (Show)
data Edge = Edge Node Node Int deriving (Show)

findNode :: [Node] -> Int -> Maybe Node
findNode nodes n = find ((== n) . index) nodes

readIntTuple3 :: String -> (Int, Int, Int)
readIntTuple3 s = (xs !! 0, xs !! 1, xs !! 2)
	where xs = map read $ words s

parseEdge :: [Node] -> String -> Maybe Edge
parseEdge nodes s = liftM3 Edge (findNode nodes node1) (findNode nodes node2) (Just dist)
	where (node1, node2, dist) = readIntTuple3 s

main = forever $ do
	node_count <- getLine
	node_values <- getLine
	let nodes = zipWith Node [1..(read node_count)] $ (map read) . words $ node_values
	edge_count <- getLine
	edge_values <- sequence $ replicate (read edge_count) getLine
	let graph = map (parseEdge nodes) edge_values
	putStrLn $ show graph
