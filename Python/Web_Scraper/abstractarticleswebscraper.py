"""Abstract web scraper for articles.

Represent an abstract articles webscraper, it get informations from website and
format them.
"""
from article import Article
from typing import List
from selenium.webdriver.firefox.options import Options
from selenium import webdriver
from datetime import date


class AbstractArticlesWebScraper:
    """Represent an abstract articles web scraper.

    It get informations from website and format them.
    """

    def __init__(self):
        """Constructor, init articles list and firefox webdriver."""
        # Init articles list
        self._articles: List[Article] = []

        # Configure Firefox driver to run in headless mode
        customOptions = Options()
        customOptions.add_argument("--headless")
        self._driver = webdriver.Firefox(options=customOptions)

    def __del__(self):
        """Destructor, close webdriver."""
        self._driver.close()

    def execute(self, since_date: date):
        """Fill the _articles attributes."""
        pass

    def getArticles(self) -> List[Article]:
        """Return articles list."""
        return self._articles

    def __str__(self) -> str:
        """Return string representation."""
        res: str = ""
        for article in self._articles:
            res += str(article)+"\n"
        return res
