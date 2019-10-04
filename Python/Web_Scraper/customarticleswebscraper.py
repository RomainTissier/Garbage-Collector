"""Custom article web scraper.

Get articles from custom website
"""
from datetime import date, datetime
from abstractarticleswebscraper import AbstractArticlesWebScraper
from selenium.common.exceptions import NoSuchElementException
from article import Article
from selenium.webdriver.remote import webelement
from pathlib import Path


class CustomArticlesWebScraper(AbstractArticlesWebScraper):
    """Get articles from custom website."""

    def execute(self, since_date: date):
        """Fill the __articles attribute."""
        current_date: date = date.today()

        # Load local example html file
        input_file = Path.cwd() / "input.html"
        url: str = input_file.as_uri()

        print("GET "+str(url))
        self._driver.get(url)

        # Debug help : print source code
        # print(self._driver.page_source)

        # Loop over articles elements
        articles_elements = self._driver.find_elements_by_xpath(
            '//div[@customattribute="customvalue"]')

        for article_element in articles_elements:
            article: Article = Article()
            article.setTitle(self.__parse_title(article_element))
            article.setDescription(self.__parse_description(article_element))

            # Update current date and break if necessary
            current_date = self.__parse_date(article_element)
            article.setDate(current_date)
            if(current_date < since_date):
                break

            # Add current article in articles liste
            self._articles.append(article)

    def __parse_date(self, article_element: webelement) -> date:
        """Parse date (child of the current element)."""
        date_element = article_element.find_element_by_xpath(
            './/span[@date="published_date"]')
        return datetime.strptime(date_element.text, "%d/%m/%Y").date()

    def __parse_description(self, article_element: webelement) -> str:
        """Parse description (child of the current element)."""
        description_element = article_element.find_element_by_class_name(
            "description")
        return description_element.text

    def __parse_title(self, art_element: webelement) -> str:
        """Parse title (child of the article element)."""
        res: str = "No title"
        try:
            title_element: webelement = art_element.find_element_by_tag_name(
                "h1")
            res = title_element.text
        except NoSuchElementException:
            pass
        return res
