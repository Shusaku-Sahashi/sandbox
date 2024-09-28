main = do ns <- getContents
          print $ length $ lines ns
