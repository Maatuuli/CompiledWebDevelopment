/*
 * Compile as a .jar package with this command:
 * ?> javac -d ./test_case_a01/classes -classpath "./selenium-server-4.10.0.jar" ./Helper.java ./test_case_a01/FrontendTest.java; cd ./test_case_a01/classes; jar cfm ../../test_case_a01.jar ../../manifest.mf ./*.class; cd -
 * 
 * Execute with:
 * ?> java -jar test_case_a01.jar
 * 
 * Show details from the JAR file with:
 * ?> jar tvf test_case_a01.jar
 *
 */

import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.logging.LogEntries;
import org.openqa.selenium.logging.LogEntry;
import org.openqa.selenium.logging.LogType;


public class FrontendTest
{    
    public static void
    main(String[] consoleArguments)
    {
        Helper.appendTextToLogFile("");
        Helper.appendTextToLogFile("# Test Case A01: \"Are HTML elements like nav, main, footer and debug section available on homepage.\"");
        Helper.appendTextToLogFile("");
        Helper.appendTextToLogFile("Steps for reproduce: ");
        
        WebDriver driver = Helper.getChromeWebDriver();

        /* Resize browser dimension to desktop monitor size. */
        driver.manage().window().setSize(new Dimension(1600, 900));

        String url = Helper.getBaseUrlForAutomatedTests();

        try
        {
            Helper.appendTextToLogFile("* go to url: " + url);
            driver.get(url);
        }
        catch (Exception exception)
        {
            if (null != driver)
            {
                driver.close();
                driver.quit();
            }

            Helper.appendTextToLogFile("[ERROR] FrontendTest crashed!");
            System.exit(0);
        }

        /* Check if actual URL is equal to expected URL! */
        String currentUrl = driver.getCurrentUrl();
        if (!currentUrl.equals(url))
        {
            Helper.appendTextToLogFile("[ERROR] FrontendTest #1 stopped: Actual URL \"" + currentUrl + "\" is not like expected URL \"" + url + "\"!");
            System.exit(0);
        }

        /* Check HTTP status code! */
        LogEntries logEntries = driver.manage().logs().get(LogType.BROWSER);
        int statusCode = Helper.getHttpStatusCodeByBrowserLogs(logEntries, url, currentUrl);
        if (200 != statusCode)
        {
            Helper.appendTextToLogFile("[ERROR] FrontendTest #1 stopped: Wrong HTTP status code " + statusCode + " was found!");

            if (null != driver)
            {
                driver.close();
                driver.quit();
            }

            System.exit(0);
        }

        /* Check existence for important parts of the page! */
        String[] textsForXpath = {"//nav", "//main", "//footer", "//div[@id='debug_section']"};

        for( int i = 0; i <= textsForXpath.length - 1; i++)
        {
            Helper.appendTextToLogFile("* check with DOM inspector for the HTML element \"" + textsForXpath[i] + "\"");
            WebElement element = Helper.getWebElementByXpath(driver, textsForXpath[i]);
            
            if (null == element)
            {
                Helper.appendTextToLogFile("[ERROR] FrontendTest #1 stopped: " + textsForXpath[i] + " was not found!");
                System.exit(0);
            }
        }
        
        Helper.appendTextToLogFile("");

        driver.close();
        driver.quit();
        
        System.exit(0);
    }
}
