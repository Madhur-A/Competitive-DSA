



object Solution {
    def removeSubfolders(folders: Array[String]): List[String] = {
        val fSorted = folders.sorted
        fSorted.tail.foldLeft(List[String](fSorted.head)) { case (res, folder) =>
            val (lastLen, currLen) = (res.head.length, folder.length)
            ((currLen <= lastLen) || (res.head != folder.substring(0, lastLen)) || (folder(lastLen) != '/')) match {
                case  true => folder :: res
                case false => res
            }
        }.reverse
    }
}
