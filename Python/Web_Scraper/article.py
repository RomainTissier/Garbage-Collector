"""Article object.

Describe a simple article
"""
from datetime import date


class Article:
    """Describe a simple article."""

    def __init__(self, title: str = None, published_date: date = None,
                 description: str = None):
        """Constructor, init Article object."""
        self.__title: str = title
        self.__date: date = published_date
        self.__description: str = description

    def __str__(self) -> str:
        """Object to string."""
        res = "date = "+str(self.__date)+", "
        res += "title = \""+str(self.__title)+"\", "
        res += "description = \""+str(self.__description)+"\";"
        return res

    def __hash__(self):
        """Two articles are the same if the title is the same."""
        return hash(self.__title)

    def __eq__(self, other):
        """Two articles are the same if the title is the same."""
        res: bool = False
        if self.getTitle() == other.getTitle():
            res = True
        return res

    def setTitle(self, title: str = None):
        """Set title."""
        self.__title = title

    def setDate(self, new_date: date = None):
        """Set date."""
        self.__date = new_date

    def setDescription(self, description: str = None):
        """Set description."""
        self.__description = description

    def getTitle(self) -> str:
        """Get Title."""
        return self.__title

    def getDate(self) -> date:
        """Get date."""
        return self.__date

    def getDescription(self) -> str:
        """Get description."""
        return self.__description
